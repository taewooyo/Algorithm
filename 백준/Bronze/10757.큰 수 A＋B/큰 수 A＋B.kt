fun main() {
    val br = System.`in`.bufferedReader()
    val (a, b) = br.readLine()!!.split(" ")
    println(plus(a, b))
}

fun plus(_a: String, _b: String): String {
    var ret = ""
    var sum = 0
    var a = _a
    var b = _b
    while(a.isNotEmpty() || b.isNotEmpty() || sum != 0) {
        if(a.isNotEmpty()) {
            sum += a[a.lastIndex] - '0'
            a = a.substring(0, a.lastIndex)
        }
        if(b.isNotEmpty()) {
            sum += b[b.lastIndex] - '0'
            b = b.substring(0, b.lastIndex)
        }
        ret += (sum % 10).toString()
        sum /= 10
    }
    return ret.reversed()
}