/** @file
  Base Memory Library functions implementation bases on PeiServcie.

  Copyright (c) 2006 - 2018, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "MemLibInternals.h"

/**
  Copies a source buffer to a destination buffer, and returns the destination buffer.

  This function wraps the gPS->CopyMem ().

  @param  DestinationBuffer   The pointer to the destination buffer of the memory copy.
  @param  SourceBuffer        The pointer to the source buffer of the memory copy.
  @param  Length              The number of bytes to copy from SourceBuffer to DestinationBuffer.

  @return DestinationBuffer.

**/
VOID *
EFIAPI
InternalMemCopyMem (
  OUT     VOID        *Destination,
  IN      CONST VOID  *Source,
  IN      UINTN       Length
  )
{
  (*GetPeiServicesTablePointer ())->CopyMem (
                                      Destination,
                                      (VOID *)Source,
                                      Length
                                      );
  return Destination;
}

/**
  Fills a target buffer with a byte value, and returns the target buffer.

  This function wraps the gPS->SetMem ().

  @param  Buffer    Memory to set.
  @param  Size      The number of bytes to set.
  @param  Value     Value of the set operation.

  @return Buffer.

**/
VOID *
EFIAPI
InternalMemSetMem (
  OUT     VOID   *Buffer,
  IN      UINTN  Size,
  IN      UINT8  Value
  )
{
  (*GetPeiServicesTablePointer ())->SetMem (
                                      Buffer,
                                      Size,
                                      Value
                                      );
  return Buffer;
}
