using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using GraphWrapper;
using System.Reflection;



namespace FirstGraphUser
{
    class Program
    {
        [StructLayout(LayoutKind.Sequential)]
        public struct Node
        {
            public Double X;
            public Double y;
            public Int32 num;
        }
       

        static void Main(string[] args)
        {


            using (var nativeUser = new FirstGraphWrapper())
            {
                
        unsafe
                {

                    String simple= nativeUser.works;
                 nativeUser.AddNode(nativeUser.a);  

                    Console.WriteLine("Inside "+simple +"We have "+nativeUser.NodeNum()+" nodes !");
                }
                Console.ReadLine();

                }
        }
    }
}
