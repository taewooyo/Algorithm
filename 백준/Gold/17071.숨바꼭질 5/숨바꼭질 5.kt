import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val st = StringTokenizer(br.readLine()!!)
    val a = st.nextToken().toInt()
    var b = st.nextToken().toInt()
    val dy = intArrayOf(1, 1, 2)
    val dx = intArrayOf(-1, 1, 0)
    val maxN = 500000
    val visit = Array(2) { IntArray(maxN + 1) { 0 } }
    var turn = 1
    var ok = false

    if (a == b) println(0)
    else {
        val q: Queue<Int> = LinkedList<Int>()
        visit[0][a] = 1
        q.add(a)

        while (q.size != 0) {
            b += turn
            if (b > maxN) break
            if (visit[turn % 2][b] != 0) {
                ok = true
                break
            }
            val qSize = q.size
            for (i in 0 until qSize) {
                val x = q.poll()
                for (j in 0 until 3) {
                    val nx = (x + dx[j]) * dy[j]
                    if (nx < 0 || nx > maxN || visit[turn % 2][nx] != 0) continue
                    if (nx == b) {
                        ok = true
                        break
                    }
                    visit[turn % 2][nx] = visit[(turn + 1) % 2][x] + 1
                    q.add(nx)
                }
            }
            if (ok) break
            turn++
        }
        if (ok) println(turn)
        else println(-1)
    }
}