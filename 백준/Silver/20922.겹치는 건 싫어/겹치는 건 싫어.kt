import java.util.*
import java.io.*
fun main() {
    val br = System.`in`.bufferedReader()
    var st = StringTokenizer(br.readLine()!!)
    val n = st.nextToken()!!.toInt()
    val k = st.nextToken()!!.toInt()

    st = StringTokenizer(br.readLine()!!)
    val arr = IntArray(n) { st.nextToken()!!.toInt() }
    var cnt = IntArray(100004)
    var l = 0
    var r = 0
    var ret = 0
    while(r < n) {
        if(cnt[arr[r]] != k) {
            cnt[arr[r]]++
            r++
        }
        else {
            cnt[arr[l]]--
            l++
        }
        ret = ret.coerceAtLeast(r - l)
    }
    println(ret)
}