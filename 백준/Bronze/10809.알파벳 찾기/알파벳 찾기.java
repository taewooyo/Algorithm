import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static String s;
    static int[] alpha = new int[26];
    static void input() {
        Arrays.fill(alpha, -1);
        s = scan.nextLine();
    }
    static void pro() {
        for(int i = 0; i < s.length(); i++) {
            if(alpha[s.charAt(i) - 'a'] != -1) continue;
            alpha[s.charAt(i) - 'a'] = i;
        }
        for(int i = 0; i < 26; i++) System.out.print(alpha[i] + " ");
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