import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int x = Integer.parseInt(br.readLine());

        int cross_cnt = 1, prev_sum = 0;
        while (true) {
            if (x <= prev_sum + cross_cnt) {
                if (cross_cnt % 2 == 1) {
                    bw.write(cross_cnt - (x - prev_sum - 1) + "/" + (x - prev_sum));
                    break;
                } else {
                    bw.write((x - prev_sum) + "/" + (cross_cnt - (x - prev_sum - 1)));
                    break;
                }
            } else {
                prev_sum += cross_cnt;
                cross_cnt++;
            }
        }

        bw.flush();
        bw.close();
    }

}
