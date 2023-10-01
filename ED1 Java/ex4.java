import java.util.Scanner;

class ex4{

    public static void main(String args[])
    {
        double base = 0;
        double altura = 0;
        double area = 0;
        Scanner s = new Scanner(System.in);

        System.out.print("Entrar com a base do triangulo: ");
        base = s.nextDouble();
        System.out.print("Entrar com a altura do triangulo: ");
        altura = s.nextDouble();

        area = (base * 1/4) * (altura * 1/4);
        System.out.print("Area com um quarto dos lados: " + area);
        s.close();

    }
}