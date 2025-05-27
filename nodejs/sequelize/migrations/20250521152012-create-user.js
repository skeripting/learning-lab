"use strict";
/** @type {import('sequelize-cli').Migration} */
module.exports = {
  /* I ran the following command:
  npx sequelize-cli model:generate --name User --attributes first_name:string,last_name:string

  And it created this migration file. It has an up function and a down function. When we're running the 
  migration, it runs the up function. If we undo the migration, it runs the down function.

  Instead of manually changing the database each time, a migration file is written and Sequelize runs
  it for you. This is better than the normal GUI based SQL because migrations are code.

  You can see who did what across large teams via commit messages. Also, there's undoing with
  migrations.
  */
  async up(queryInterface, Sequelize) {
    await queryInterface.createTable("Users", {
      id: {
        allowNull: false,
        autoIncrement: true,
        primaryKey: true,
        type: Sequelize.INTEGER,
      },
      first_name: {
        type: Sequelize.STRING,
      },
      last_name: {
        type: Sequelize.STRING,
      },
      created_at: {
        allowNull: false,
        type: Sequelize.DATE,
      },
      updated_at: {
        allowNull: false,
        type: Sequelize.DATE,
      },
    });
  },
  async down(queryInterface, Sequelize) {
    await queryInterface.dropTable("Users");
  },
};
