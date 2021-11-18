# defer
## test code
```c++
#include <iostream>;
#include "defer.h"

int main()
{
    DEFER_BEGIN
        std::cout << "defer 1 " << std::endl;
    DEFER_END
    DEFER_BEGIN
        std::cout << "defer 2" << std::endl;
    DEFER_END
    DEFER_BEGIN
        std::cout << "defer 3" << std::endl;
    DEFER_END

    std::cout << "done" << std::endl;
}
```
`MSVC v142 Tested`
## out
<pre>
<code>
done
defer 3
defer 2
defer 1
</code>
</pre>
