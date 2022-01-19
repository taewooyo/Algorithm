import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int up = Integer.parseInt(st.nextToken());
        int down = Integer.parseInt(st.nextToken());
        int len = Integer.parseInt(st.nextToken());

        int day = (len - down) / (up - down);
        if ((len - down) % (up - down) != 0)
            day++;

        bw.write(String.valueOf(day));
        bw.flush();
        bw.close();
    }

}
