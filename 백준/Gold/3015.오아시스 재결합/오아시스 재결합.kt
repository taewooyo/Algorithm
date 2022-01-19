import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine()!!.toInt()
    val s = Stack<Pair<Long, Long>>()
    var ret = 0L

    for(i in 0 until n) {
        val x = br.readLine()!!.toLong()
        var cnt = 1L
        while(s.size != 0 && s.peek().first <= x) {
            ret += s.peek().second
            cnt = if(s.peek().first == x) s.peek().second + 1 else 1
            s.pop()
        }
        if(s.size != 0) ret++
        s.add(Pair(x, cnt))
    }
    
    println(ret)
}