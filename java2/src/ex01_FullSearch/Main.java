package ex01_FullSearch;

import java.io.*;
import java.util.StringTokenizer;

/*
    <완전 탐색>
        - 문제를 해결하기 위해 확인해야 하는 모든 경우를 전부 탐색하는 방법.
        - 그 중에서도 백 트래킹을 통해야 하는 상황을 해결하기.
*/
/*
    <문제>
        - 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램 작성.
            1) 1부터 N까지 자연수 중에서 M개를 고른 수열
            2) 같은 수를 여러번 골라도 된다.
            입력: 첫째 줄에 자연수 N과 M이 주어진다. (1 <= M <= N <=7)
            출력: 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다.
                  ( 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 사전 순으로 증가하는 순서로 출력해야 한다. )
*/
public class Main {

    static StringBuilder sb = new StringBuilder();
    static int N, M;
    static int[] selected;

    static void input() {
        FastReader scan = new FastReader();
        N = scan.nextInt();
        M = scan.nextInt();
        selected = new int[M + 1];
    }

    // Recurrence Function (재귀 함수)
    // 만약 M 개를 전부 고름 => 조건에 맞는 탐색을 한 가지 성공한 것!
    // 아직 M 개를 고르지 않음 => k 번째부터 M번째 원소를 조건에 맞게 고르는 모든 방법을 시도한다.
    static void rec_func1(int k) {
        if(k == M + 1) {    // 다 골랐다!
            // selected[1...M] 배열이 새롭게 탐색된 결과
            for(int i=1 ; i<=M ; i++) {
                sb.append(selected[i]).append(' ');
            }
            sb.append('\n');
        } else {
            for(int candidate=1 ; candidate<=N ; candidate++) {
                selected[k] = candidate;
                // k+1 번지 ~ M 번지 요소를 모두 탐색.
                rec_func1(k+1);
                selected[k] = 0; // 의례상..
            }
        }
    }
    public static void main(String[] args) {

        input();

        // 1 번째 원소부터 M 번째 원소를 조건에 맞는 모든 방법을 찾아줘!
        rec_func1(1);

        System.out.println(sb);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(new File(s)));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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
