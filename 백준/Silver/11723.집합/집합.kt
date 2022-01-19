import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readLine()!!.toInt()
    var ret = 0
    repeat(n) {
        val st = StringTokenizer(br.readLine()!!)
        val command = st.nextToken()
        var x = 0
        when(command) {
            "add" -> {
                x = st.nextToken().toInt()
                ret = ret or (1 shl x) // ret |= (1 << x)
            }
            "remove" -> {
                x = st.nextToken().toInt()
                ret = ret and (1 shl x).inv() // ret &= ~(1 << x)
            }
            "check" -> {
                x = st.nextToken().toInt() // ret & (1 << x)
                val a = if(ret and (1 shl x) != 0) 1 else 0
                sb.append("$a\n")
            }
            "toggle" -> {
                x = st.nextToken().toInt()
                ret = ret xor (1 shl x) // ret ^= (1 << x)
            }
            "all" -> ret = (1 shl 21) - 1
            "empty" -> ret = 0
        }
    }
    print(sb)
}