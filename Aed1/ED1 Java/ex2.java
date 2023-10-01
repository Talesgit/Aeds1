import java.util.Scanner;

class ex2{

    public static void main(String args[])
    {
        int valor = 0;
        Scanner s = new Scanner(System.in);
        System.out.println("Entrar com valor: ");
        valor = s.nextInt();
        valor = valor/2;
        int area = valor * 4;
        int perimetro = valor * 4;
        System.out.println("Perimetro com metado do lado: " + perimetro);
        System.out.println("Area com metado do lado: " + area);
        s.close();
    }
}