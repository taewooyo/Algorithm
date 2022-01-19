import java.io.*;
import java.util.*;
/*
1. 임대료, 재산세, 보험료, 급여 등 A만원의 고정 비용
2. 한 대 노트북 생산하는데 재료비와 인건비 총 B만원 가변 비용
3. 노트북 가격이 C * x 만원 > A+B될 때, 최초로 총 수입이 총 비용보다 많아져 이익이 발생하는 지점은?
 */
public class Main {

    static int a, b, c;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        a = toInt(st.nextToken());
        b = toInt(st.nextToken());
        c = toInt(st.nextToken());

        if(c <= b) {
            bw.write(String.valueOf(-1));
        }
        else bw.write(String.valueOf((a/(c-b))+1));
        bw.flush();
        bw.close();
    }

    static int toInt(String element) {
        return Integer.parseInt(element);
    }
}
