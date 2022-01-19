import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());

        int cnt = 0;
        while (true) {
            if (N % 5 == 0) {
                cnt += N / 5;
                break;
            }
            else if(N < 0) {
                cnt = -1;
                break;
            }
            N = N - 3;
            cnt++;
        }
        sb.append(cnt);
        System.out.println(sb);
    }

}
