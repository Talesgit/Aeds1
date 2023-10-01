import java.util.Scanner;

class ex {

    public static void parRec(int valor) {
        if (valor > 0) {
            parRec(valor - 1);
            System.out.println(2 * (valor - 1) + 6);
        }
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int valor = 0;

        System.out.print("Quantos valores pares mostrar: ");
        valor = s.nextInt();

        parRec(valor);
        s.close();
    }
}
