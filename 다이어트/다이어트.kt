import java.util.*
import java.io.*
fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine()!!.toInt()
    var st = StringTokenizer(br.readLine()!!)
    val condition = IntArray(4) {st.nextToken().toInt()}
    val items = Array(n) {
        st = StringTokenizer(br.readLine()!!)
        IntArray(5) { st.nextToken().toInt() }
    }

    var price = 987654321
    var check = ""
    val total = IntArray(5)

    for (choice in 1 until (1 shl n)) {
        total.fill(0)

        var current = choice
        repeat(n) {
            if (current and (1 shl it) != 0) {
                repeat(5) { idx ->
                    total[idx] += items[it][idx]
                }
            }
        }

        var valid = true
        repeat(4) {
            if (total[it] < condition[it]) valid = false
        }

        if (valid) {
            val temp = StringBuilder().apply {
                var cur = choice
                repeat(n) {
                    if (cur and (1 shl it) != 0) append(it+1).append(' ')
                }
            }.toString()

            if(total[4] < price) {
                price = total[4]
                check = temp
            } else if(total[4] == price && check > temp) check = temp
        }
    }

    println(if(price == 987654321) "-1" else "$price\n$check")
}