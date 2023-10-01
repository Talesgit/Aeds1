import java.util.Scanner;
import java.lang.String;

public class ex4 {
    public static void isLetter(String palavra) {
        int count = 0;
        int tam = palavra.length();
        for (int i = 0; i < tam; i++) {
            if (palavra.charAt(i) >= 'a' && palavra.charAt(i) <= 'z'
                    || palavra.charAt(i) >= 'A' && palavra.charAt(i) <= 'Z') {
                System.out.println(palavra.charAt(i));
                count++;
            }
        }
        System.out.println("Simbolos que sao letras: " + count);
    }

    public static void main(String args[]) {
        String palavra;
        Scanner s = new Scanner(System.in);
        do {
            palavra = s.nextLine();
            if (palavra.compareTo("FIM") != 0) {
                isLetter(palavra);
            }
        } while (palavra.compareTo("FIM") != 0);
        s.close();
    }
}
