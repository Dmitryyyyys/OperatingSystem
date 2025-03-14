using System;
using System.Diagnostics;
using System.Threading;

class Program
{
    const int ThreadCount = 10;           // Количество потоков
    const int ThreadLifeTime = 10;        // Время жизни потока
    const int ObservationTime = 30;       // Время наблюдения
    static int[,] Matrix = new int[ThreadCount, ObservationTime];
    static DateTime StartTime = DateTime.Now;

    static void WorkThread(object o)
    {
        int id = (int)o;
        for (int i = 0; i < ThreadLifeTime * 20; i++)
        {
            DateTime CurrentTime = DateTime.Now;
            int ElapsedSeconds = (int)Math.Round(CurrentTime.Subtract(StartTime).TotalSeconds - 0.49);

            if (ElapsedSeconds >= 0 && ElapsedSeconds < ObservationTime)
            {
                Matrix[id, ElapsedSeconds] += 50;
            }

            MySleep(50);
        }
    }

    static void Main(string[] args)
    {
        Process.GetCurrentProcess().ProcessorAffinity = (System.IntPtr)15;  // Ограничение по процессорам (для 4 логических процессоров)
        Thread[] t = new Thread[ThreadCount];

        for (int i = 0; i < ThreadCount; ++i)
        {
            object o = i;
            t[i] = new Thread(WorkThread);

            // Устанавливаем приоритеты для потоков в зависимости от их индекса
            switch (i % 3)
            {
                case 0:
                    t[i].Priority = ThreadPriority.Lowest;
                    break;
                case 2:
                    t[i].Priority = ThreadPriority.Highest;
                    break;
            }

            t[i].Start(o);
        }

        Console.WriteLine("A student ... is waiting for the threads to finish");

        for (int i = 0; i < ThreadCount; ++i)
        {
            t[i].Join();
        }

        // Вывод результатов
        // Вывод результатов
        for (int s = 0; s < ObservationTime; s++)
        {
            Console.Write("{0,3}: ", s);
            for (int th = 0; th < ThreadCount; th++)
            {
                Console.Write(" T{0}:{1,5}", th, Matrix[th, s]);
            }
            Console.WriteLine();
        }

    }

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
