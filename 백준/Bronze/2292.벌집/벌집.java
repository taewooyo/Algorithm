import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int layer = 1;
        int layer_cnt = 0;
        int total_cnt = 1;
        int n = Integer.parseInt(br.readLine());

        while (true) {
            if (n <= total_cnt) break;
            else {
                layer_cnt += 6;
                total_cnt += layer_cnt;
                layer++;
            }
        }
        bw.write(String.valueOf(layer));
        bw.flush();
        bw.close();
    }

}
