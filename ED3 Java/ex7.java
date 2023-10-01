import java.util.Scanner;

public class ex7 {
    public static void verifyIntv(int nums[], int limM, int limMenor) {
        int tam = nums.length;
        int count = 0;
        System.out.println("Valores quesatisfazem: ");
        for (int i = 0; i < tam; i++) {
            if (nums[i] % 3 == 0 && nums[i] >= limMenor && nums[i] <= limM) {
                System.out.println(nums[i]);
                count++;
            }
        }
        System.out.println("Multiplos de 3 e estao no intervalo: " + count);
    }

    public static void main(String argc[]) {
        Scanner s = new Scanner(System.in);
        int quantidade = 0;
        int limMA = 0;
        int limME = 0;

        System.out.println("Quantidade a serem testados: ");
        quantidade = s.nextInt();

        System.out.print("Lim maior: ");
        limMA = s.nextInt();

        System.out.print("Lim menor: ");
        limME = s.nextInt();

        int nums[] = new int[quantidade];

        for (int i = 0; i < quantidade; i++) {
            nums[i] = s.nextInt();
        }

        verifyIntv(nums, limMA, limME);
        s.close();
    }
}
