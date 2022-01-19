import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static String s;
    static int sum;
    static void input() {
        s = scan.next();
    }

    static void pro() {
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c >= 'A' && c <= 'C') sum += 3;
            if(c >= 'D' && c <= 'F') sum += 4;
            if(c >= 'G' && c <= 'I') sum += 5;
            if(c >= 'J' && c <= 'L') sum += 6;
            if(c >= 'M' && c <= 'O') sum += 7;
            if(c >= 'P' && c <= 'S') sum += 8;
            if(c >= 'T' && c <= 'V') sum += 9;
            if(c >= 'W' && c <= 'Z') sum += 10;
        }
        System.out.println(sum);
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