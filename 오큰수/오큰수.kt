import java.util.*

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readLine()!!.toInt()
    val arr = br.readLine()!!.split(" ").map { it.toInt() }
    val ret = IntArray(n) { -1 }

    val stk = Stack<Int>()

    for(i in arr.indices) {
        while(!stk.empty() && arr[stk.peek()] < arr[i]) {
            ret[stk.peek()] = arr[i]
            stk.pop()
        }
        stk.add(i)
    }

    ret.forEach { sb.append("$it ") }
    println(sb)

}