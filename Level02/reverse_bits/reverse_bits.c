unsigned char reverse_bits(unsigned char octet)
{
    unsigned char res = 0;
    int i = 8;

    while (i--)
    {
        res = (res << 1) | (octet & 1);  // Shift result left and add the LSB of octet
        octet >>= 1;  // Shift octet right to get the next bit
    }
    return res;
}
