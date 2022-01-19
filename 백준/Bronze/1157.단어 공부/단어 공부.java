import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static String s;
    static int[] alpha = new int[26];
    static void input() {
        s = scan.next();
    }

    static void pro() {
        String str = s.toUpperCase();
        for(int i = 0; i < str.length(); i++) {
            alpha[str.charAt(i) - 'A']++;
        }
        int idx = 0;
        int max = 0;
        char answer = '?';
        for(int i = 0; i < 26; i++) {
            if(alpha[i] > max) {
                max = alpha[i];
                answer = (char) (i + 'A');
            }
            else if(max == alpha[i]) {
                answer = '?';
            }
        }
        System.out.println(answer);
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