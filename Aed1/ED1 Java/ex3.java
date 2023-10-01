import java.util.Scanner;

class ex3{
    public static void main(String args[])
    {
        int base = 0;
        int altura = 0;
        int area = 0;
        Scanner s = new Scanner(System.in);

        System.out.print("Entrar com base: ");
        base = s.nextInt();
        System.out.print("Entrar com altura: ");
        altura = s.nextInt();
        area = base * altura * 3;

        System.out.println("3 x a area do retangulo = " + area);
    }
}