// http://c.learncodethehardway.org/book/ex17.html

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Contact {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  struct Contact rows[MAX_ROWS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};

void die(const char *message) {
  if(errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

void Contact_print(struct Contact *c) {
  printf("%d %s %s\n", c->id, c->name, c->email);
}

void Database_load(struct Connection *conn) {
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if(rc != 1) die("Failed to load database");
}

struct Connection *Database_open(const char *filename, char mode) {
  struct Connection *conn = malloc(sizeof(struct Connection));
  if(!conn) die("Memory error.");

  conn->db = malloc(sizeof(struct Database));
  if(!conn->db) die("Memory error");

  if(mode == 'c') {
    conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+");

    if(conn->file) {
      Database_load(conn);
    }
  }

  if(!conn->file) die("Failed to load file");

  return conn;
}

void Database_close(struct Connection *conn) {
  if(conn) {
    if(conn->file) fclose(conn->file);
    if(conn->db) free(conn->db);
    free(conn);
  }
}

void Database_write(struct Connection *conn) {
  rewind(conn->file);

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if(rc != 1) die("Failed to write database");

  rc = fflush(conn->file);
  if(rc == -1) die("Failed to flush database");
}

void Database_create(struct Connection *conn) {
  int i = 0;

  for(i=0; i < MAX_ROWS; i++) {
    struct Contact c = { .id = i, .set = 0 };
    conn->db->rows[i] = c;
  }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
  struct Contact *c = &conn->db->rows[id]; // TODO: what does the & do to a struct pointer?
  if(c->set) die("Contact already set, delete it first");

  c->set = 1;
  // WARNING: bug, read the "How To Break It" and fix this
  char *res = strncpy(c->name, name, MAX_DATA);
  if(!res) die("Name copy failed");

  res = strncpy(c->email, email, MAX_DATA);
  if(!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id) {
  struct Contact *c = &conn->db->rows[id];
  if(c->set) {
    Contact_print(c);
  } else {
    die("ID not set");
  }
}

void Database_delete(struct Connection *conn, int id) {
  struct Contact c = { .id = id, .set = 0 };
  conn->db->rows[id] = c;
}

void Database_list(struct Connection *conn) {
  int i = 0;
  struct Database *db = conn->db;

  for(i = 0; i < MAX_ROWS; i++) {
    struct Contact *cursor = &db->rows[i];

    if(cursor->set) {
      Contact_print(cursor);
    }
  }
}

int main(int argc, char *argv[]) {
  if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

  char *filename = argv[1];
  char action = argv[2][0];

  struct Connection *conn = Database_open(filename, action);
  int id = 0;

  if(argc > 3) id = atoi(argv[3]);
  if(id >= MAX_ROWS) die("There's not that many records.");

  switch(action) {
    case 'c':
      Database_create(conn);
      Database_write(conn);
      break;
    case 'g':
      if(argc != 4) die("Need an id to get");
      Database_get(conn, id);
      break;
    case 's':
      if(argc != 6) die("Need id, name, email to set");
      Database_set(conn, id, argv[4], argv[5]);
      Database_write(conn);
      break;
    case 'd':
      if(argc != 4) die("Need id to delete");
      Database_delete(conn, id);
      Database_write(conn);
      break;
    case 'l':
      Database_list(conn);
      break;
    default:
      die("Invalid action, only: c=create, g=get, s=set, d=del, l=list");
  }

  Database_close(conn);

  return 0;
}
