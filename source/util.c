/*************************************************************************
 * Authors: Antonio M. Ferreira, PhD [1,2]                               *
 *          David Coss, PhD [1]                                          *
 *                                                                       *
 *          (1) High Performance Computing Faclity                       *
 *              Research Informatics, Information Sciences               *
 *                                                                       *
 *          (2) Structural Biology                                       *
 *                                                                       *
 *          St. Jude Children's Research Hospital                        *
 *                                                                       *
 * Effercio is free software: you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * Effercio is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with Effercio. If not, see <http://www.gnu.org/licenses/>.      *
 *************************************************************************/

#include "util.h"

#include <stdarg.h>
#include <errno.h>
#include <stdio.h>

static void reason_exit_vargs(va_list args, const char *format)
{
  vfprintf(stderr,format,args);
  va_end(args);
  if(errno != 0)
  {
      fprintf(stderr,"Reason (%d): %s\n",errno,strerror(errno));
      exit(errno);
  }
  exit(1);
}

static void reason_exit(const char *format, ...)
{
  va_list args;
  va_start(args,format);
  reason_exit_vargs(args,format);
}

void full_assert(int condition,const char *format,...)
{
    va_list args;
    if(condition)
        return;
    va_start(args,format);
    reason_exit_vargs(args,format);
} 

