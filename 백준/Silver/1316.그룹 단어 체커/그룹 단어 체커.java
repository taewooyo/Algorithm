import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static int N;
    static String s;
    static boolean alpha[] = new boolean[26];
    static void input() {
        N = scan.nextInt();
    }

    static boolean isOk(String s) {
        Arrays.fill(alpha, false);

        int prev = -1;
        for(int i = 0; i < s.length(); i++) {
            int now = s.charAt(i) - 'a';

            // 앞선 문자와 다르다면
            if(prev != now) {
                if(alpha[now] == false) {
                    alpha[now] = true;
                    prev = now;
                }
                else return false;
            }
            else continue;
        }
        return true;
    }

    static void pro() {
        int answer = 0;
        for(int i = 0; i < N; i++) {
            s = scan.next();
            if(isOk(s)) answer++;
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