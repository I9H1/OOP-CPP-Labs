#pragma once

class BitArray {
    private:
        char data;
    public:
        class Wrapper {
            private:
                BitArray *link;
                int index;
        };
};
