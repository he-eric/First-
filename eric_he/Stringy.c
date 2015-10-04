#include <stdio.h>

int strlength( char *str );
void strcopy( char d[], char s[] );
void strconcatn( char n[], char d[], char s[], int i );
int strcomp( char a[], char b[] );
int strchar( char a[], char c);
int strstring( char a[], char b[] );

int main() {
  char *str = "string";
  char *wrd = "word";
  char src[] = "source";
  char dest[] = "destination";
  char concat[ strlength(dest) + strlength(src) ];
  char empty[100];
  char a[] = "abc";
  char b[] = "ab";
  int i = 1;
  
  printf( "Testing strlength with string: %s\n", str );
  printf( "String length: %d \n", strlength( str ) );
  printf( "Testing strlength with string: %s\n", wrd );
  printf( "String length: %d\n", strlength( wrd ) );

  printf( "\n" );

  printf( "Testing strcopy with string: %s\n", src );
  printf( "Testing strcopy with string: %s\n", empty );
  strcopy( empty, src );
  printf("Empty string is now: %s\n", empty );

  
  printf( "\n" );
  
  printf( "Testing strconcat with string: %s\n", src );
  printf( "Testing strconcat with string: %s\n", dest );
  printf( "Appends the first: %d character(s) \n", i );
  strconcatn( concat, dest, src, i );
  printf( "Concatenated string: %s\n", concat );
  
  printf( "\n" );

  printf( "Testing strcomp with string: abc and ab \n" );
  printf( "%d\n", strcomp( a, b ) );
  printf( "Testing strcomp with string: abc and abc \n" );
  printf( "%d\n", strcomp( a, a ) );
  printf( "This answer is wrong! Still working on it." );

  printf( "\n" );

  printf( "Testing strchar with string: %s. Return place if found -1 if not found\n", src );
  printf( "Looking for s \n" );
  printf( "%d\n", strchar( src, 's' ) );
  printf( "Looking for 1 \n" );
  printf( "%d\n", strchar( src, '1' ) );
  printf( "Looking for e \n" );
  printf( "%d\n", strchar( src, 'e' ) );
  
  printf( "\n" );
  
  printf( "Testing strstring with strings %s and %s. Return 1 if found -1 if not found \n", a, b );
  printf( "%d This answer is wrong! I used my strcomp (broken method for now) in this method which is why it churned out the wrong answer. \n", strstring( a, b ) );
  
  return 0;
}

int strlength( char *str ) {
  int len = 0;
  while ( *str++ ) 
    len++;
  return len;
}

void strcopy( char d[], char s[] ) {
  int place = 0;
  while ( s[place] != 0 ) {
    d[place] = s[place];
    place++;
  }
  d[place] = '\0';
}

void strconcatn( char n[], char d[], char s[], int i ) {
  strcopy( n, d );
  int nplace = strlength( d );
  int splace = 0;
  while ( splace != i ) { 
    n[nplace] = s[splace];
    nplace++;
    splace++;
  }
  n[nplace] = '\0';
}

int strcomp( char a[], char b[] ) {
  int c = 0;
  while ( a[c] != '\0' || b[c] == '\0' ) { 
    if ( a[c] == b[c] )
      if ( c == ( strlength( a ) - 1 ) && c == ( strlength( b ) - 1 ) )
	return 1;
      else 
	return -1;
    c++;
  }
  return -1;
}

int strchar( char a[], char c ) {
  int place = 0;
  while ( a[place] != '\0' ) {
    if ( a[place] == c )
      return place;
    place++;
  }
  return -1;
}

int strstring( char a[], char b[] ) {
  int i;
  int j;
  for (i = 0; i < strlength( a ); i++ ) {
    j = 0;
    char c[100];
    while ( j < strlength( b ) ) {
      c[j] = b[j];
      j++;
    }
    if ( strcomp( c, b ) == 1 )
      return 1;
  }
  return -1;
}



