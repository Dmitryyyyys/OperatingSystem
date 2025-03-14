using System;
using System.Diagnostics;
using System.Threading.Tasks;

class Program
{
    const int TaskCount = 16;           // Количество задач равно количеству логических процессоров
    const int TaskLifeTime = 40;        // Время жизни задачи
    const int ObservationTime = 120;    // Время наблюдения
    static int[,] Matrix = new int[TaskCount, ObservationTime]; // Таблица для хранения статистики
    static DateTime StartTime;

    static void Work(int id)
    {
        for (int i = 0; i < TaskLifeTime * 20; i++)
        {
            DateTime currentTime = DateTime.Now;
            int elapsedSeconds = (int)Math.Round(currentTime.Subtract(StartTime).TotalSeconds - 0.49);

            // Проверка на выход за границы массива
            if (elapsedSeconds >= ObservationTime)
                break;

            Matrix[id, elapsedSeconds] += 50; // Обновление статистики
            MySleep(50); // Симуляция длительной работы
        }
    }

    static void Main(string[] args)
    {
        StartTime = DateTime.Now;
        Console.WriteLine("Запуск задач...");

        for (int i = 0; i < TaskCount; i++)
        {
            int taskId = i;  // Важно захватить переменную taskId

           
            Task task = Task.Run(() => Work(taskId));
            task.Wait();  
        }

        // Вывод таблицы статистики
        Console.WriteLine("Статистика работы потоков:");
        for (int s = 0; s < ObservationTime; s++)
        {
            Console.Write("{0,3}: ", s);
            for (int th = 0; th < TaskCount; th++)
                Console.Write(" {0,5}", Matrix[th, s]);
            Console.WriteLine();
        }
    }

    // Эмуляция работы с потреблением процессорного времени
    static void MySleep(int ms)
    {
        Stopwatch stopwatch = Stopwatch.StartNew();
        double sum = 0;

        while (stopwatch.ElapsedMilliseconds < ms)
        {
            for (int k = 0; k < 1000; k++)
            {
                sum += Math.Sqrt(k) * Math.Cos(k);
            }
        }
    }
}
