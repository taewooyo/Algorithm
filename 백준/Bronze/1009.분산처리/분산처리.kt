fun main() {
    val br = System.`in`.bufferedReader()
    val t = br.readLine()!!.toInt()

    repeat(t) {
        val (a, b) = br.readLine()!!.split(" ").map { it.toInt() }
        val ans = getTotalData(a, b)
        println(if(ans == 0) 10 else ans)
    }
}

fun getTotalData(a: Int, b: Int): Int {
    if(b == 1) return a % 10
    var ret = getTotalData(a, b / 2)
    ret = ret * ret % 10

    if(b % 2 != 0) ret = ret * a % 10
    return ret
}