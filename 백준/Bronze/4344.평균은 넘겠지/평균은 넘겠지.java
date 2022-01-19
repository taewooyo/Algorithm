import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static int C;
    static int[] arr;
    static void input() throws IOException {
        C = Integer.parseInt(scan.br.readLine());
    }

    static void pro() {
        for(int i = 0; i < C; i++) {
            StringTokenizer token = new StringTokenizer(scan.nextLine(), " ");
            int n = Integer.parseInt(token.nextToken());
            arr = new int[n];
            double sum = 0.0;
            for(int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(token.nextToken());
                sum += arr[j];
            }

            int num = 0;
            double avg = sum / n;
            for(int j = 0; j < n; j++) {
                if(arr[j] > avg) num++;
            }
            System.out.printf("%.3f", 100.0 * num / n);
            System.out.println("%");
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch(IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}