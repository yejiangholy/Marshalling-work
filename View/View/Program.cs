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
        [DllImport("Touch.dll",CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        static extern void createGraph(double arg1, double arg2, int arg3, string str,int size);

        [DllImport("Touch.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        static extern void getOutPut(StringBuilder output, int length);

        static void Main(string[] args)
        {


            string inputGraph = System.IO.File.ReadAllText(@"C:\Users\yjiang\Documents\Visual Studio 2013\Projects\erdiagram.gml");
            int inputSize = inputGraph.Length;
            double arg1 = 20.0;
            double arg2 = 16.0;
            int arg3 = 5;

            createGraph(arg1, arg2, arg3, inputGraph, inputSize);
            //System.Threading.Thread.Sleep(300);

            StringBuilder outPuts = new StringBuilder(30000);
            getOutPut(outPuts, outPuts.Capacity);

            Console.WriteLine(outPuts.ToString());
            Console.ReadLine();
        }
    }
}
