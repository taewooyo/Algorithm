import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer token;

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            token = new StringTokenizer(br.readLine(), " ");
            sb.append(Integer.parseInt(token.nextToken()) + Integer.parseInt(token.nextToken()) + "\n");
        }

        System.out.println(sb);
        br.close();
    }
}
