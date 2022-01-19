import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

//    static void input() {
//    }
    static final int N = 10001;
    static int[] arr = new int[N];
    static int go(int number) {
        int sum = number;
        while(true) {
            if(number == 0) break;
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }

    static void pro() {
        for(int i = 1; i < N; i++) {
            int idx = go(i);
            if(idx < N) {
                arr[idx] = 1;
            }
        }
        for(int i = 1; i < N; i++) {
            if(arr[i] == 0) sb.append(i).append("\n");
        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args){
//        input();
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