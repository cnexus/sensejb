#define CRCPOLY_LE 0xedb88320
#define CRCPOLY_BE 0x04c11db7

<<<<<<< HEAD
#define CRC32C_POLY_LE 0x82F63B78

=======
/*
 * This is the CRC32c polynomial, as outlined by Castagnoli.
 * x^32+x^28+x^27+x^26+x^25+x^23+x^22+x^20+x^19+x^18+x^14+x^13+x^11+x^10+x^9+
 * x^8+x^6+x^0
 */
#define CRC32C_POLY_LE 0x82F63B78

/* Try to choose an implementation variant via Kconfig */
>>>>>>> b00e38e... crc32 - 13 patches in 1 commit
#ifdef CONFIG_CRC32_SLICEBY8
# define CRC_LE_BITS 64
# define CRC_BE_BITS 64
#endif
#ifdef CONFIG_CRC32_SLICEBY4
# define CRC_LE_BITS 32
# define CRC_BE_BITS 32
#endif
#ifdef CONFIG_CRC32_SARWATE
# define CRC_LE_BITS 8
# define CRC_BE_BITS 8
#endif
#ifdef CONFIG_CRC32_BIT
# define CRC_LE_BITS 1
# define CRC_BE_BITS 1
#endif

<<<<<<< HEAD
=======
/*
 * How many bits at a time to use.  Valid values are 1, 2, 4, 8, 32 and 64.
 * For less performance-sensitive, use 4 or 8 to save table size.
 * For larger systems choose same as CPU architecture as default.
 * This works well on X86_64, SPARC64 systems. This may require some
 * elaboration after experiments with other architectures.
 */
>>>>>>> b00e38e... crc32 - 13 patches in 1 commit
#ifndef CRC_LE_BITS
#  ifdef CONFIG_64BIT
#  define CRC_LE_BITS 64
#  else
#  define CRC_LE_BITS 32
#  endif
#endif
#ifndef CRC_BE_BITS
#  ifdef CONFIG_64BIT
#  define CRC_BE_BITS 64
#  else
#  define CRC_BE_BITS 32
#  endif
#endif

<<<<<<< HEAD
=======
/*
 * Little-endian CRC computation.  Used with serial bit streams sent
 * lsbit-first.  Be sure to use cpu_to_le32() to append the computed CRC.
 */
>>>>>>> b00e38e... crc32 - 13 patches in 1 commit
#if CRC_LE_BITS > 64 || CRC_LE_BITS < 1 || CRC_LE_BITS == 16 || \
	CRC_LE_BITS & CRC_LE_BITS-1
# error "CRC_LE_BITS must be one of {1, 2, 4, 8, 32, 64}"
#endif

<<<<<<< HEAD
=======
/*
 * Big-endian CRC computation.  Used with serial bit streams sent
 * msbit-first.  Be sure to use cpu_to_be32() to append the computed CRC.
 */
>>>>>>> b00e38e... crc32 - 13 patches in 1 commit
#if CRC_BE_BITS > 64 || CRC_BE_BITS < 1 || CRC_BE_BITS == 16 || \
	CRC_BE_BITS & CRC_BE_BITS-1
# error "CRC_BE_BITS must be one of {1, 2, 4, 8, 32, 64}"
#endif
