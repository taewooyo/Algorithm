import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static int N;
    static ArrayList<String> arr = new ArrayList<>();
    static void input() {
        N = scan.nextInt();
        for(int i = 0; i < N; i++) {
            arr.add(scan.nextLine());
        }
    }

    static void pro() {
        for(int i = 0; i < arr.size(); i++) {
            int sum = 0;
            int score = 1;
            for(int j = 0; j < arr.get(i).length(); j++) {
                if(arr.get(i).charAt(j) == 'O') {
                    sum += score;
                    score++;
                }
                else score = 1;
            }
            sb.append(sum).append("\n");
        }
        System.out.println(sb.toString());
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