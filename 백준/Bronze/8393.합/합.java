import java.io.*;
import java.util.*;

public class Main {
    static int sum = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer token;

        int n = Integer.parseInt(br.readLine());
        for(int i = 1; i <= n; i++) sum += i;

        sb.append(sum);
        System.out.println(sb);
        br.close();
    }
}
