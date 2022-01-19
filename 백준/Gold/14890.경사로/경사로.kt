import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val (n, l) = br.readLine()!!.split(" ").map { it.toInt() }
    var a = Array(n) {
        var st = StringTokenizer(br.readLine()!!)
        IntArray(n) {
            st.nextToken().toInt()
        }
    }
    var ret = 0
    var b = Array(n) { IntArray(n) }
    for(i in a.indices)
        for (j in a[i].indices)
            b[j][i] = a[i][j]

    fun go(tmp: Array<IntArray>) {
        repeat(n) {i->
            var cnt = 1
            var j = 0
            while(j < n - 1) {
                if(tmp[i][j] == tmp[i][j+1]) cnt++
                else if(tmp[i][j] + 1 == tmp[i][j+1] && cnt >= l) cnt = 1
                else if(tmp[i][j] - 1 == tmp[i][j+1] && cnt >= 0) cnt = -l + 1
                else break
                j++
            }
            if(j == n - 1 && cnt >= 0) ret++
        }
    }

    go(a)
    go(b)
    println(ret)
}