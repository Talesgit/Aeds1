import java.util.Scanner;
import java.lang.String;

public class ex2 {
    public static void contarMaiusculas(String word)
    {
        int length = word.length();
        int maiusculas = 0;
        for(int i = 0; i < length; i++)
        {
            if(word.charAt(i) >= 'A' && word.charAt(i) <= 'Z')
            {
                System.out.println(word.charAt(i));
                maiusculas++;
            }
        }
        System.out.println("Quantidade de maiusculas: " + maiusculas);
    }

    public static void main(String args[])
    {
        String word;
        Scanner s = new Scanner(System.in);

        do
        {
            System.out.print("Entrar com palavra: ");
            word = s.nextLine();
            
            if(word.compareTo("FIM") != 0)
            {
                contarMaiusculas(word);
            }

        }while(word.compareTo("FIM") != 0);
        s.close();
    }
}
