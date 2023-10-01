import java.util.Scanner;
import java.lang.String;

class ex1{
    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Entre com a medida dos lados do quadrado: ");
        double l = s.nextInt();
        double area = l * l;
        System.out.print("A area do circulo e: " + area);
        s.close();
    }
}
