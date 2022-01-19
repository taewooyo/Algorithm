import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static int N;
    static void input() {
        N = scan.nextInt();
    }

    static int hansu(int x) {
        int cnt = 0;
        if(x < 100) return x;

        cnt = 99;
        if(x == 1000) {
            x = 999;
        }

        for(int i = 100; i <= x; i++) {
            int hun = i / 100;
            int ten = (i/10)%10;
            int one = i%10;
            if((hun - ten) == (ten - one)) cnt++;
        }
        return cnt;
    }

    static void pro() {
        System.out.println(hansu(N));
    }

    public static void main(String[] args){
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