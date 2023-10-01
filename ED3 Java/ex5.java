import java.util.Scanner;
import java.lang.String;

public class ex5 {
    public static void showDigits(String term)
    {
        int tam = term.length();
        int count = 0;
        for(int i = tam - 1; i >= 0; i--)
        {
            if(term.charAt(i) >= '!' && term.charAt(i) <= '~')//term.charAt(i) >= 'a' && term.charAt(i) <= 'z' || (term.charAt(i) >= '0' && term.charAt(i) <= '9'))
            {
                System.out.println(term.charAt(i));
                count++;
            }
        }
        System.out.println("Quantidade de digitos: " + count);
    }

    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        String term;

        do
        {
            term = s.nextLine();
            if(term.compareTo("FIM") != 0)
            {
                showDigits(term);
            }

        }while(term.compareTo("FIM") != 0);
        s.close();

    }
}
