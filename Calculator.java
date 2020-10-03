class Func
{
   int num1,num2;
   void getData(int a,int b)
   {
     num1=a;
     num2=b;
   }
   int add()
   { return (num1+num2);}
   int sub()
   { return (num1-num2);}
   int mul()
   { return (num1*num2);}
   int div()
   { return (num1/num2);}
   int pon=1;   
   int pow()
   {
     for(int i=0;i<num2;i++)
     {
        pon=pon*num1;   
     }
     return (pon);
   }
}
class Calculator
{
   public static void main(String args[])
   {
     Func f1=new Func();
     int x=Integer.parseInt(args[1]);
     int y=Integer.parseInt(args[2]);
     int z=Integer.parseInt(args[0]);
     f1.getData(x,y);
     if(z==1){System.out.println(f1.add());}
     else if(z==2){System.out.println(f1.sub());}
     else if(z==3){System.out.println(f1.mul());}
     else if(z==4){System.out.println(f1.div());}
     else if(z==5){System.out.println(f1.pow());}
   }
}