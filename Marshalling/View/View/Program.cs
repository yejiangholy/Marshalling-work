using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;


namespace View
{
    class Program
    {
        [DllImport("Controler.dll", CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern void createGraph(string str , int size); //send string to C++

        [DllImport("Controler.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        static extern void getOutPut(StringBuilder output, int length); //get string from C++

        [DllImport("Controler.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void sendArrayDouble(double[] doubles); //send array of double to C++

        [DllImport("Controler.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void getDoulbes(ref int count,
                                              [MarshalAs(UnmanagedType.LPArray,SizeConst =5)]
                                             double[] array); // get array of double from C++

        [DllImport("Controler.dll", CallingConvention = CallingConvention.Cdecl, SetLastError = true)]
        public static extern void sendArrayOfString(string[] strings, int size);// send array of string to C++

        [DllImport("Controler.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void getArrayOfString(ref int size,
                                                 [MarshalAs(UnmanagedType.LPArray,ArraySubType = UnmanagedType.LPTStr, SizeConst = 100)]
                                                  string[] strings); //get array of string from C++


        static void Main(string[] args)
        {
            createGraph("01234567" , 8);

            string s1 = "s1"; string s2 = "s2";
            string s3 = "s3"; string s4 = "s4";
            string[] strings = { s1, s2, s3, s4 };
            sendArrayOfString(strings, 4);

            Double[] points = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5 };
            sendArrayDouble(points);

            int count = 0;
            double[] doubles = new double[5];
            getDoulbes( ref count , doubles);

            Console.WriteLine(doubles[0]);
            Console.WriteLine(doubles[1]);
            Console.WriteLine(doubles[2]);
            Console.WriteLine(doubles[3]);
            Console.WriteLine(doubles[4]);

            //int size = 0;
            //string[] week = new string[7];
            //getArrayOfString(ref size, week);
            //Console.WriteLine(week[0]);


            StringBuilder outPuts= new StringBuilder(100);
            getOutPut(outPuts, outPuts.Capacity);

            Console.WriteLine(outPuts.ToString());
            Console.ReadLine();
        }
    }
}
