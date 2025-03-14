using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    const int TaskCount = 10;
    const int ThreadCount = 40;           // Количество потоков
    const int ThreadLifeTime = 40;        // Время жизни потока (в 20 итерациях)
    const int ObservationTime = 120;        // Время наблюдения
    static int[,] Matrix = new int[ThreadCount, ObservationTime]; // Двумерный массив для хранения данных
    static DateTime StartTime;             // Время начала работы

    static void WorkThread(object o)
    {
        int id = (int)o;                   // Получаем ID потока
        for (int i = 0; i < ThreadLifeTime * 20; i++)
        {
            DateTime CurrentTime = DateTime.Now;
            int EllapsedSeconds = (int)Math.Round(CurrentTime.Subtract(StartTime).TotalSeconds - 0.49);

            // Проверка на выход за границы массива
            if (EllapsedSeconds >= ObservationTime)
                break; // Прерываем цикл, если время наблюдения превышено

            Matrix[id, EllapsedSeconds] += 50; // Обновление массива
            MySleep(50); // Вызов функции ожидания
        }
    }

    static void Work(int id)
    {
        for (int i = 0; i < ObservationTime; i++)
        {
            // Обновляем данные в массиве Matrix
            Matrix[id, i] += 1; // Заполняем данными
            Task.Delay(1000).Wait(); // Имитация длительной работы (задержка на 1 секунду)
        }
    }
    static void Main(string[] args)
    {
        Task[] tasks = new Task[TaskCount]; // Массив задач

        Console.WriteLine("A student ... is creating tasks...");
        for (int i = 0; i < TaskCount; i++)
        {
            int id = i; // Уникальный идентификатор для каждой задачи
            tasks[i] = Task.Run(() => Work(id)); // Запуск задачи
        }

        Console.WriteLine("A student ... is waiting for tasks to finish...");
        Task.WaitAll(tasks); // Ожидание завершения всех задач

        // Вывод результатов
        for (int s = 0; s < ObservationTime; s++)
        {
            Console.Write("{0,3}: ", s);
            for (int th = 0; th < TaskCount; th++)
            {
                Console.Write(" {0,5}", Matrix[th, s]);
            }
            Console.WriteLine();
        }
    }

static void MySleep(int ms)
    {
        Stopwatch stopwatch = Stopwatch.StartNew();
        double Sum = 0;

        // Цикл ожидания, выполняющий вычисления
        while (stopwatch.ElapsedMilliseconds < ms)
        {
            for (int k = 0; k < 1000; k++)
            {
                Sum += Math.Sqrt(k) * Math.Cos(k);
            }
        }
    }
}
