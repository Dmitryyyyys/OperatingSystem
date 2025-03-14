using System.Diagnostics;
using System;
using System.Management;
class Program
{
    static void Main(string[] args)
    {
        int logicalProcessorCount = Environment.ProcessorCount;
        int physicalCoreCount = GetPhysicalCoreCount();
        Console.WriteLine($"Количество логических процессоров: {logicalProcessorCount}");
        Console.WriteLine($"Количество физ ядер: {physicalCoreCount}");

        Console.WriteLine("Начало выполнения MySleep(10000)");
        MySleep(10000);
        Console.WriteLine("Завершено выполнение MySleep(10000)");
    }
static int GetPhysicalCoreCount()
    {
        int coreCount = 0;
        try
        {
            using (var searcher = new ManagementObjectSearcher("SELECT * FROM Win32_Processor"))
            {
                foreach(ManagementObject item in searcher.Get())
                {
                    coreCount += Convert.ToInt32(item["NumberofCores"]);
                }
              }
        }
   catch (Exception ex)
        {
            Console.WriteLine("Ошибка при получении информации о процессорах: " + ex.Message);
    }
        return coreCount;        
    }
static void MySleep(int ms)
    {
        Stopwatch stopwatch = Stopwatch.StartNew();
        double Sum = 0;
        while (stopwatch.ElapsedMilliseconds < ms)
        {
            for(int k = 0; k < 1000;k++)
            {
                Sum += Math.Sqrt(k) * Math.Cos(k);
            }
        }
        stopwatch.Stop(); 
    }
}