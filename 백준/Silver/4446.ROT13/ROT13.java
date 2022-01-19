import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static String original;
    static char[] check1 = {'a', 'i', 'y', 'e', 'o', 'u'};
    static char[] check11 = {'A', 'I', 'Y', 'E', 'O', 'U'};
    static char[] check2 = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};
    static char[] check22 = {'B', 'K', 'X', 'Z', 'N', 'H', 'D', 'C', 'W', 'G', 'P', 'V', 'J', 'Q', 'T', 'S', 'R', 'L', 'M', 'F'};
    static void input() {
        while((original = scan.nextLine()) != null) {
            sb = new StringBuilder();
            pro();
        }
    }

    static void pro() {
        for(int i = 0; i < original.length(); i++) {
            boolean flag = false;
            for(int j = 0; j < check1.length; j++) {
                if(original.charAt(i) == check1[j]) {
                    flag = true;
                    sb.append(check1[(j + 3) % check1.length]);
                }
            }
            for(int j = 0; j < check11.length; j++) {
                if(original.charAt(i) == check11[j]) {
                    flag = true;
                    sb.append(check11[(j + 3) % check11.length]);
                }
            }

            for(int j = 0; j < check2.length; j++) {
                if(original.charAt(i) == check2[j]) {
                    flag = true;
                    sb.append(check2[(j + 10) % check2.length]);
                }
            }
            for(int j = 0; j < check22.length; j++) {
                if(original.charAt(i) == check22[j]) {
                    flag = true;
                    sb.append(check22[(j + 10) % check22.length]);
                }
            }
            if(!flag) sb.append(original.charAt(i));

        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args) throws IOException {
        input();
//        pro();
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
