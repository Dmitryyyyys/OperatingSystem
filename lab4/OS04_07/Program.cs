using System;
using System.Diagnostics;
using System.Threading;

class Program
{
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

    static void Main(string[] args)
    {
        StartTime = DateTime.Now; // Инициализация времени начала
        Thread[] t = new Thread[ThreadCount];

        for (int i = 0; i < ThreadCount; ++i)
        {
            t[i] = new Thread(WorkThread);
            t[i].Start(i); // Запускаем поток с ID
        }

        Console.WriteLine("A student ... is waiting for the threads to finish");

        for (int i = 0; i < ThreadCount; ++i)
            t[i].Join(); // Ожидание завершения потоков

        // Вывод результатов
        for (int s = 0; s < ObservationTime; s++)
        {
            Console.Write("{0,3}:   ", s);
            for (int th = 0; th < ThreadCount; th++)
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
