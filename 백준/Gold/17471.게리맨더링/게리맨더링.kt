import java.util.*
import kotlin.math.abs

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine()!!.toInt()
    var st = StringTokenizer(br.readLine()!!)
    val a = IntArray(n) { st.nextToken().toInt() }
    var adj = Array(11) { mutableListOf<Int>()}
    var comp = IntArray(11)
    var visited = IntArray(11)
    var ret = 987654321

    repeat(n) { i ->
        st = StringTokenizer(br.readLine()!!)
        var m = st.nextToken().toInt()
        repeat(m) {
            val temp = st.nextToken().toInt()
            adj[i+1].add(temp)
            adj[temp].add(i+1)
        }
    }

    fun dfs(here: Int, value: Int) : Int {
        visited[here] = 1
        var tmp = a[here-1]
        for(there in adj[here]) {
            if(comp[there] != value) continue
            if(visited[there] != 0) continue
            tmp += dfs(there, value)
        }
        return tmp
    }

    for (i in 1 until (1 shl n)-1) {
        comp.fill(0)
        visited.fill(0)

        var idx1 = -1
        var idx2 = -1
        for (j in 0 until n) {
            if (i and (1 shl j) != 0) {
                comp[j+1] = 1
                idx1 = j + 1
            }
            else
                idx2 = j + 1
        }

        var comp1 = dfs(idx1, 1)
        var comp2 = dfs(idx2, 0)
        var cnt = 0
        for (i in 1..n) if(visited[i] != 0) cnt++
        if(cnt == n) ret = ret.coerceAtMost(abs(comp1 - comp2))
    }

    println(if(ret == 987654321) -1 else ret)
}