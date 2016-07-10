enum pwrap_reg_attr{
	RW,
	RO,
	WO,
	RU,
};
unsigned int pmic_wrap_reg_tbl[][4] = {
	//offset, default value,      write 1
    {  0x0, 0x00000000  , 0x00000001  , RW},
    {  0x4, 0x00000000  , 0x00000001  , RW},
    {  0x8, 0x00000000  , 0x00000003  , RW},
    {  0xC, 0x00000000  , 0x00000003  , RW},
    { 0x10, 0x000000FF  , 0x000000FF  , RW},
    { 0x14, 0x00000001  , 0x00000007  , RW},
    { 0x18, 0x0000000F  , 0x0000000F  , RW},
    { 0x1C, 0x0000000F  , 0x0000000F  , RW},
    { 0x20, 0x0000000F  , 0x0000000F  , RW},
    { 0x24, 0x0000000F  , 0x0000000F  , RW},
    { 0x28, 0x00000000  , 0x0000000F  , RW},
    { 0x2C, 0x0000000C  , 0x000000FF  , RW},
    { 0x30, 0x00000000  , 0x0000FFFF  , RW},
    { 0x34, 0x00000000  , 0x0000FFFF  , RW},
    { 0x38, 0x00000000  , 0x0000000F  , RO},
    { 0x3C, 0x00000000  , 0x0000000F  , WO},
    { 0x40, 0x00000000  , 0x00000001  , WO},
    { 0x44, 0x00000000  , 0x000001FF  , RU},
    { 0x48, 0x00000280  , 0x00007FFF  , RU},
    { 0x4C, 0x00000000  , 0x00000001  , RW},
    { 0x50, 0x00000000  , 0x0000003F  , RW},
    { 0x54, 0x00000000  , 0x0000003F  , RW},
    { 0x58, 0x00000000  , 0xFFFFFFFF  , RU},
    { 0x5C, 0x02000005  , 0x000FFFFF  , RU},
    { 0x60, 0x00000000  , 0x00000001  , RW},
    { 0x64, 0x00000000  , 0x00003FFF  , RW},
    { 0x68, 0x00000000  , 0x00000FFF  , RU},
    { 0x6C, 0x00000000  , 0x00000001  , WO},
    { 0x70, 0x00000000  , 0x00000001  , RW},
    { 0x74, 0x00000000  , 0x00000001  , RW},
    { 0x78, 0x00000000  , 0xFFFFFFFF  , RW},
    { 0x7C, 0x80500000  , 0xFF7FFFFF  , RU},
    { 0x80, 0x00000000  , 0x00000001  , WO},
    { 0x84, 0x00000000  , 0x00000001  , RW},
    { 0x88, 0x00000000  , 0x00000001  , RW},
    { 0x8C, 0x00000000  , 0xFFFFFFFF  , RW},
    { 0x90, 0x80500000  , 0xFF7FFFFF  , RU},
    { 0x94, 0x00000000  , 0x00000001  , WO},
    { 0x98, 0x00000000  , 0x00000001  , RW},
    { 0x9C, 0x00000000  , 0x00000001  , RW},
    { 0xA0, 0x00000000  , 0xFFFFFFFF  , RW},
    { 0xA4, 0x80500000  , 0xFF7FFFFF  , RU},
    { 0xA8, 0x00000000  , 0x00000001  , WO},
    { 0xAC, 0x00000000  , 0x00000001  , RW},
    { 0xB0, 0x00000000  , 0xFFFFFFFF  , RU},
    { 0xB4, 0x00000000  , 0xFFFFFFFF  , RU},
    { 0xB8, 0x00000000  , 0xFFFFFFFF  , WO},
    { 0xBC, 0x00000000  , 0xFFFFFFFF  , WO},
    { 0xC0, 0x00000000  , 0x00000003  , RW},
    { 0xC4, 0x00000000  , 0xFFFFFFFF  , RU},
    { 0xC8, 0x00000000  , 0xFFFFFFFF  , RU},
    { 0xCC, 0x00000000  , 0x00000001  , WO},
    { 0xD0, 0x00000000  , 0x00000001  , RW},
    { 0xD4, 0x00000000  , 0x1FFFFFFF  , RU},
    { 0xD8, 0x00000000  , 0x0000000F  , RW},
    { 0xDC, 0x00000000  , 0xFFFFFFFF  , RU},
    { 0xE0, 0x00000000  , 0xFFFFFFFF  , RU},
    { 0xE4, 0x00000000  , 0x00000001  , RW},
    { 0xE8, 0x00000000  , 0x0000FFFF  , RU},
    { 0xEC, 0x00000000  , 0x0000000F  , RW},
    { 0xF0, 0x00000000  , 0x0000FFFF  , RW},
    { 0xF4, 0x00000000  , 0x0000FFFF  , RU},
    { 0xF8, 0x00000000  , 0x00000007  , RW},
    { 0xFC, 0x00000000  , 0x0000FFFF  , RW},
    {0x100, 0x00000000  , 0x0000FFFF  , RW},
    {0x104, 0x00000000  , 0x0000FFFF  , RW},
    {0x108, 0x00000000  , 0x0000FFFF  , RW},
    {0x10C, 0x00000000  , 0x0000FFFF  , RW},
    {0x110, 0x00000000  , 0x0000FFFF  , RW},
    {0x114, 0x00000000  , 0x0000FFFF  , RW},
    {0x118, 0x00000000  , 0x0000FFFF  , RW},
    {0x11C, 0x00000000  , 0x0000FFFF  , RW},
    {0x120, 0x00000000  , 0x0000FFFF  , RW},
    {0x124, 0x00000000  , 0x0000FFFF  , RW},
    {0x128, 0x00000000  , 0x000007FF  , RU},
    {0x12C, 0x00000000  , 0x00000003  , RW},
    {0x130, 0x00000000  , 0x00000003  , RW},
    {0x134, 0x00000000  , 0x00000001  , RW},
    {0x138, 0x00000000  , 0x00000003  , RU},
    {0x13C, 0x00000000  , 0x00000001  , RW},
    {0x140, 0x00000000  , 0x00000001  , RW},
    {0x144, 0x00000000  , 0x00000003  , RW},
    {0x148, 0x00000000  , 0x000000FF  , RW},
    {0x14C, 0x00000000  , 0x00000001  , RW},
    {0x150, 0x00000000  , 0x0000FFFF  , RW},
    {0x154, 0x00000000  , 0x0000FFFF  , RW},
    {0x158, 0x00000000  , 0x0000FFFF  , RW},
    {0x15C, 0x00000000  , 0x0000FFFF  , RW},
    {0x160, 0x00000000  , 0x0000FFFF  , RW},
    {0x164, 0x00000000  , 0x0000FFFF  , RW},
    {0x168, 0x00000000  , 0x0000FFFF  , RW},
    {0x16C, 0x00000000  , 0x0000FFFF  , RW},
    {0x170, 0x00000000  , 0x0000FFFF  , RW},
    {0x174, 0x00000000  , 0x0000FFFF  , RW},
    {0x178, 0x00000000  , 0x0000FFFF  , RW},
    {0x180, 0x00000000  , 0x00000003  , RW},
    {0x184, 0x00000000  , 0x00000003  , RW},
    {0x188, 0x00000000  , 0x00000001  , RW},
    {0x190, 0x00000000  , 0x00000001  , RW},
    {0x194, 0x00000000  , 0x00000001  , RW},
    {0x198, 0x00000000  , 0x00000003  , RW},
    {0x1A0, 0x00000000  , 0x00000001  , RW},
    {0x1A0, 0x00000000  , 0x00000001  , RW},
    {0x1A4, 0x00000000  , 0x0000ffff  , RW},
    {0x1A8, 0x00000000  , 0x0000ffff  , RW},
    {0x1Ac, 0x00000004  , 0x0000ffff  , RW},
    {0x1B4, 0x00000000  , 0x00000001  , RW},
    {0x1B8, 0x00000008  , 0x0000ffff  , RW},
    {0x1Bc, 0x0000000a  , 0x0000ffff  , RW},
    {0x1cc, 0x0000000a  , 0x0000ffff  , RW},
    {0x1d0, 0x0000000a  , 0x0000ffff  , RW},
    {0x228, 0x0000000a  , 0x0000ffff  , RW},
    {0x22c, 0x0000000a  , 0x0000ffff  , RW},
    {0x230, 0x0000000a  , 0x0000ffff  , RW},
    {0x234, 0x0000000a  , 0x0000ffff  , RW},
    {0x238, 0x0000000a  , 0x0000ffff  , RW},
    {0x23c, 0x0000000a  , 0x0000ffff  , RW},
    
};