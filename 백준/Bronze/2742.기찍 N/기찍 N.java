import java.io.*;
import java.util.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token;

        int n = Integer.parseInt(br.readLine());
        for(int i = n; i > 0; i--) {
            sb.append(i + "\n");
        }
        System.out.println(sb);
        br.close();
    }
}
