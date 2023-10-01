import java.util.Scanner;
import java.lang.String;

class ex1 {

    public static void isMaiuscula(String palavra) {
        int tam = palavra.length();
        for (int i = 0; i < tam; i++) {
            if (palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z') {
                System.out.println(palavra.charAt(i));
            }
        }
    }

    public static void main(String args[]) {
        String palavra;
        Scanner s = new Scanner(System.in);

        do {

            System.out.print("Entrar com palavra: ");
            palavra = s.nextLine();

            if (palavra.compareTo("FIM") != 0) {
                isMaiuscula(palavra);
            }

        } while (palavra.compareTo("FIM") != 0);
        s.close();
    }
}